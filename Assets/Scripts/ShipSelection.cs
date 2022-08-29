using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShipSelection : MonoBehaviour
{
    public static ShipSelection Instance;
    [HideInInspector]
    public string shipName;
    // Start is called before the first frame update
    private void Awake()
    {
        if(Instance != null)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        shipName = "milleniumFalcon";
    }

    public void MilleniumFalcon()
    {
        shipName = "milleniumFalcon";
    }

    public void XWing()
    {
        shipName = "XWing";
    }

    public void Ghost()
    {
        shipName = "Ghost";
    }

    public void MandoStarfighter()
    {
        shipName = "MandoStarfighter";
    }

    public void JediStarfighter()
    {
        shipName = "JediStarfighter";
    }

    public string getShip()
    {
        return shipName;
    }
}
