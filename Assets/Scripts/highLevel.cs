using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class highLevel : MonoBehaviour
{
    public Text highest;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        highest.text = "Last Highest Level: " + PlayerPrefs.GetInt("Highest");
    }
}
