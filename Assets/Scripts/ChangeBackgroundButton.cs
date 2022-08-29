using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangeBackgroundButton : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void HighlightButton()
    {
        this.GetComponent<Image>().color = new Color(1, 159 / 255f, 0, 1);
    }
}
