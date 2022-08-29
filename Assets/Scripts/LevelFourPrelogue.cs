using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LevelFourPrelogue : MonoBehaviour
{
    [Header("Set in Inspector")]
    public GameObject levelDialogueGO;
    public Text dialogue;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void FunctionController()
    {
        if (this.GetComponentInChildren<Text>().text == "Next")
        {
            AdvanceDialogue();
        }
        else
        {
            StartLevel();
        }
    }
    public void AdvanceDialogue()
    {
        this.GetComponentInChildren<Text>().text = "Finish";
        dialogue.text = "Boba Fett: No matter! The EMPIRE has placed a bounty on your head. You're worth a lot to me, dead or alive!";
    }
    public void StartLevel()
    {
        levelDialogueGO.SetActive(false);
    }
}
