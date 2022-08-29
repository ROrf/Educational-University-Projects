using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EndGame : MonoBehaviour
{
    int score;
    public Text scoreBox;
    void Awake()
    {
        score = PlayerPrefs.GetInt("Score");
        PlayerPrefs.SetInt("Score", 0);
    }

    // Update is called once per frame
    void Update()
    {
        scoreBox.text = "Score: " + score;
    }
}
