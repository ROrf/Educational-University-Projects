using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StartLevel : MonoBehaviour
{

    [Header("Set in Inspector")]
    public GameObject ship;
    public GameObject button;
    public Sprite falcon;
    public Sprite xWing;
    public Sprite ghost;
    public Sprite mando;
    public Sprite jedi;

    // Start is called before the first frame update
    void Start()
    {
        ship.GetComponent<SpriteRenderer>().sprite = GetSprite();
        ship.SetActive(false);
        button.SetActive(true);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void LoadShip()
    {
        //print("Clicked!");
        ship.SetActive(true);
        button.SetActive(false);
    }

    public Sprite GetSprite()
    {
        string shipName = "milleniumFalcon";
        if(ShipSelection.Instance != null)
        {
            shipName = ShipSelection.Instance.shipName;
        }
        if(shipName == "milleniumFalcon")
        {
            return falcon;
        }
        else if(shipName == "XWing")
        {
            return xWing;
        }
        else if(shipName == "Ghost")
        {
            return ghost;
        }
        else if(shipName == "MandoStarfighter")
        {
            return mando;
        }
        else if(shipName == "JediStarfighter")
        {
            ship.transform.localScale = new Vector3(ship.transform.localScale.x * 2, ship.transform.localScale.y * 2, ship.transform.localScale.z * 2);
            ship.GetComponent<BoxCollider2D>().size = new Vector2(ship.GetComponent<BoxCollider2D>().size.x / 2f, ship.GetComponent<BoxCollider2D>().size.y / 2f);
            ship.GetComponent<BoxCollider2D>().offset = new Vector2(ship.GetComponent<BoxCollider2D>().offset.x / 2f, ship.GetComponent<BoxCollider2D>().offset.y / 2f);
            return jedi;
        }
        return falcon;
    }
}
