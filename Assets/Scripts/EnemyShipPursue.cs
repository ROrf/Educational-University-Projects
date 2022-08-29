using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyShipPursue : MonoBehaviour
{
    [Header("Set in Inspector")]
    public GameObject ship;
    public Vector3 origin;
    public float speed;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (ship)
        {
            if (ship.activeInHierarchy)
            {
                float step = speed * Time.deltaTime;
                Vector2 target = new Vector2(ship.transform.position.x, ship.transform.position.y);
                this.transform.position = Vector2.MoveTowards(this.transform.position, target, step);
                Vector3 difference = ship.transform.position - this.transform.position;
                difference.Normalize();
                float rotationZ = Mathf.Atan2(difference.y, difference.x) * Mathf.Rad2Deg;
                transform.rotation = Quaternion.Euler(0f, 0f, rotationZ + 90f);
            }
            else
            {
                this.transform.position = origin;
            }
        }
    }
}
