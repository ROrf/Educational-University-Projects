using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LevelThreePrelogue : MonoBehaviour
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
        if(this.GetComponentInChildren<Text>().text == "Next")
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
        dialogue.color = new Color(82 / 255f, 49 / 255f, 42 / 255f, 1);
        dialogue.text = "Qi'ra: Deliver Spice from KESSEL to our ship, the FIRST LIGHT, and we will let you travel freely in our space throughout the galaxy, including RYLOTH and the OUTER RIM!";
    }
    public void StartLevel()
    {
        levelDialogueGO.SetActive(false);
    }
}
