using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LetsTrySpinning : MonoBehaviour
{
    //Thats a good trick!

    public GameObject objectToSpin;
    public float spinRate = .2f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        objectToSpin.transform.Rotate(new Vector3(0, 0, spinRate));
    }
}
