using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyInstance : MonoBehaviour
{
    // Start is called before the first frame update
    void Awake()
    {
        if(ShipSelection.Instance != null)
        {
            Destroy(ShipSelection.Instance);
            return;
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
