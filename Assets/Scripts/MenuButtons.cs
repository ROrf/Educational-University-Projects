using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class MenuButtons : MonoBehaviour
{
    public bool paused = false;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OnClick_Start()
    {
        PlayerPrefs.SetString("Time", System.DateTime.Now.ToString());
        PlayerPrefs.SetInt("Score", 0);
        PlayerPrefs.SetInt("Highest", 0);
        SceneManager.LoadScene("_Level_1");
    }

    public void OnClick_Restart()
    {
        PlayerPrefs.SetInt("Score", 0);
        SceneManager.LoadScene("_Start_Screen");
    }

    public void OnClick_Quit()
    {
        //Application.Quit(); For when game is built
        PlayerPrefs.SetString("Time","");
        PlayerPrefs.SetInt("Score", 0);
        UnityEditor.EditorApplication.isPlaying = false; //for when the game is in Editor
    }

    public void OnClick_Pause()
    {
        if (paused)
        {
            Time.timeScale = 1.0f;
            paused = false;
        }
        else
        {
            Time.timeScale = 0.0f;
            paused = true;
        }
    }



}
