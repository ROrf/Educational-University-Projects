using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO;

public class PlayerSaver : MonoBehaviour
{
    [Header("Set in Inspector")]
    public Text feedback;
    public Text score;
    // Start is called before the first frame update
    void Start()
    {
        PlayerPrefs.SetInt("userNum", 0);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void saveData()
    {
        string path = Application.dataPath + "/playerlog.txt";

        if(!File.Exists(path))
        {
            File.WriteAllText(path, "PLAYER DATA\n\n\n");
        }



        int id = Random.Range(0, 10000);
        string playerID = "ID: " + id+"\n";
        string date = System.DateTime.Now.ToString() + "\n"; //write current dateTime
        System.DateTime startTime = System.DateTime.Parse(PlayerPrefs.GetString("Time"));
        string duration = "Duration: " + (System.DateTime.Now.Subtract(startTime)).ToString() + "\n"; //difference from NOW and when the start button was pushed
        string saveScore = score.text + "\n"; //what the user scored
        string usrFeedback = feedback.text + "\n"; //whatever the user typed

        File.AppendAllText(path, playerID);
        File.AppendAllText(path, date);
        File.AppendAllText(path, duration);
        File.AppendAllText(path, saveScore);
        File.AppendAllText(path, usrFeedback);
        File.AppendAllText(path, "\n");
        return;
    }



}
