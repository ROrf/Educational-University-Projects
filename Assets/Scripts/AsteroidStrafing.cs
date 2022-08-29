using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AsteroidStrafing : MonoBehaviour
{
    [Header("Set in Inspector")]
    public float step;
    public float radius;
    public Vector2 target1;
    public Vector2 target2;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (target1.y == target2.y)
        {
            //transform.position = new Vector2(transform.position.x + step, transform.position.y);
            if ((Mathf.Abs(transform.position.x - target1.x) <= radius) || (Mathf.Abs(transform.position.x - target2.x) <= radius))
            {
                step *= -1.0f;
            }
            transform.position = new Vector2(transform.position.x + step, transform.position.y);
        }
        else
        {
            //transform.position = new Vector2(transform.position.x, transform.position.y + step);
            if ((Mathf.Abs(transform.position.y - target1.y) <= radius || (Mathf.Abs(transform.position.y - target2.y) <= radius)))
            {
                step *= -1.0f;
            }
            transform.position = new Vector2(transform.position.x, transform.position.y + step);
        }
    }
}
