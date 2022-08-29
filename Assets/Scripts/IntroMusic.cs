using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class IntroMusic : MonoBehaviour
{
    AudioSource introTheme;
    float timer;
    // Start is called before the first frame update
    void Start()
    {
        timer = 85f;
        introTheme = GetComponent<AudioSource>();
        introTheme.Play();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        timer -= Time.deltaTime;
        if(timer <= 0f)
        {
            introTheme.Stop();
            SceneManager.LoadScene("_Start_Screen");
        }
    }

    public void LoadHomeScreen()
    {
        SceneManager.LoadScene("_Start_Screen");
    }
}
