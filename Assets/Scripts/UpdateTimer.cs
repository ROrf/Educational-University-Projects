using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class UpdateTimer : MonoBehaviour
{

    public float timer = 240f;
    public Text timerText;

    public Text scoreText;
    public float score = 0;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        timer -= Time.deltaTime;
        if(timer <= 0)
        {
            SceneManager.LoadScene("_End_Screen");
        }
        int min = (int)timer / 60;
        int sec = (int)timer - (min * 60);
        timerText.text = "Time: " + min + ":" + sec.ToString("00");

        score = PlayerPrefs.GetInt("Score");
        scoreText.text = "Score: " + score;


    }
}
