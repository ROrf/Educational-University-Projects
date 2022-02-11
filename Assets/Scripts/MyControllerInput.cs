using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit;
using System.Linq;
using UnityEngine.AI;
using UnityEngine.SceneManagement;
public class MyControllerInput : MonoBehaviour
{
    // controller input variables
    [System.Serializable]
    public class Callback : UnityEvent<Ray, RaycastHit> { }
    [SerializeField]
    private XRNode xrNodeL = XRNode.LeftHand;
    private XRNode xrNodeR = XRNode.RightHand;
    private InputDeviceRole inputDevice;
    private List<InputDevice> devices = new List<InputDevice>();
    private InputDevice device;
    public Transform leftHandAnchor = null;
    public Transform rightHandAnchor = null;
    public Transform centerEyeAnchor = null;
    public float maxRayDistance = 500;
    public LayerMask excludeLayers;
    public GameObject xrRig;
    bool triggerValue;
    bool secondaryButton;
    public Transform camera;
    // shared game variables
    public float timer;
    // red light game variables
    public GameObject redLightGame;
    public GameObject RedLightCube;
    public GameObject ColorCube;
    bool redLightStart;
    public float redLightRandNum;
    bool isRedLight;
    public GameObject redLightButton;
    public AudioSource redaudio;
    public AudioSource greenaudio;
    public Animator redgreenanimation;
    // marble game variables
    public GameObject marble;
    public GameObject marbleButton;
    public GameObject marbleReturn;
    bool marbleStart;
    public GameObject marbleGame;
    // jump puzzle game variables
    public GameObject jumpPuzzleGame;
    public GameObject jumpPuzzleButton;
    bool jumpPuzzleStart;
    public int[] jumpPlatforms = { 0, 0, 0, 0, 0, 0 };
    public BoxCollider nearRightPlatform;
    public BoxCollider nearLeftPlatform;
    public BoxCollider middleRightPlatform;
    public BoxCollider middleLeftPlatform;
    public BoxCollider farRightPlatform;
    public BoxCollider farLeftPlatform;
    public Animator nearRightDrop;
    public Animator nearLeftDrop;
    public Animator middleRightDrop;
    public Animator middleLeftDrop;
    public Animator farRightDrop;
    public Animator farLeftDrop;
    // door open variables
    public GameObject doorOpenCube;
    public Animator openDoor;
    // game manager variables
    bool redLightDone;
    bool marbleDone;
    bool jumpPuzzleDone;
    // intro canvas variables
    public GameObject introCube;
    public GameObject giHunCube;
    // exit canvas variables
    public GameObject menuCube;
    // trophies variables
    public GameObject silverCup;
    public GameObject bronzeCup;
    public GameObject goldCup;
    // particle variables
    public Transform Fireworks;
    public GameObject entranceGuard;
    void GetDevice()
    {
        InputDevices.GetDevicesAtXRNode(xrNodeL, devices);
        InputDevices.GetDevicesAtXRNode(xrNodeR, devices);
        device = devices.FirstOrDefault();
    }
    void OnEnable()
    {
        if (!device.isValid)
        {
            GetDevice();
        }
    }
    //In the awake we will find the left and right hand controllers and assign them to anchors
    private void Awake()
    {
        if (leftHandAnchor == null)
        {
            Debug.LogWarning("Assign LeftHandAnchor in the inspector!");
            GameObject left = GameObject.Find("LeftHand Controller");
            if (left != null)
            {
                leftHandAnchor = left.transform;
            }
        }
        if (rightHandAnchor == null)
        {
            Debug.LogWarning("Assign RightHandAnchor in the inspector!");
            GameObject right = GameObject.Find("RightHand Controller");
            if (right != null)
            {
                rightHandAnchor = right.transform;
            }
        }
        if (centerEyeAnchor == null)
        {
            Debug.LogWarning("Assign CenterEyeAnchor in the inspector!");
            GameObject center = GameObject.Find("CenterEyeAnchor");
            if (center != null)
            {
                centerEyeAnchor = center.transform;
            }
        }
    }
    //we can create a Pointer of type transform and assign the left or right to be active
    Transform Pointer
    {
        get
        {
            if (rightHandAnchor == null)
            {
                return leftHandAnchor;
            }
            return rightHandAnchor;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        redLightStart = false;
        timer = 0f;
        isRedLight = false;
        marbleStart = false;
        redLightDone = false;
        marbleDone = false;
        jumpPuzzleDone = false;
        menuCube.SetActive(false);
    }

    // Update is called once per frame
    [Obsolete]
    void Update()
    {
        if (!device.isValid)//checking again to make sure device is assigned
        {
            GetDevice();
        }
        Transform pointer = Pointer;
        if (pointer == null)
        {
            return;
        }

        Ray rayPointer = new Ray(pointer.position, pointer.forward);
        RaycastHit hit;
    
        // red light game
        if (redLightStart)
        {
            //ColorCube.GetComponent<Renderer>().material.SetColor("_Color", Color.green);
            UnityEngine.Random.seed = System.DateTime.Now.Millisecond;
            if (timer <= 0f)
            {
                redLightRandNum = UnityEngine.Random.Range(1.0f, 2.0f);
                if (isRedLight)
                {
                    isRedLight = false;
                    greenaudio.mute = false;
                    redaudio.mute = true;
                    redgreenanimation.Play("GreenAnimation");
                    greenaudio.Play();
                }
                else
                {
                    isRedLight = true;
                    greenaudio.mute = true;
                    redaudio.mute = false;
                    redgreenanimation.Play("RedAnimation");
                    redaudio.Play();
                }
            }
            else
            {
                if(isRedLight)
                {
                    ColorCube.GetComponent<Renderer>().material.SetColor("_Color", Color.red);
                    if (xrRig.transform.hasChanged)
                    {
                        xrRig.transform.position = new Vector3(-9.296908f, 3.703096f, -22.23538f);
                    }
                }
                else
                {
                    ColorCube.GetComponent<Renderer>().material.SetColor("_Color", Color.green);
                }
                if (timer >= redLightRandNum)
                {
                    timer = -.1f;
                }

            }
            timer += Time.deltaTime;
            xrRig.transform.hasChanged = false;
            if (xrRig.transform.position.x >= 13.879f)
            {
                redLightButton.SetActive(true);
                redLightGame.SetActive(false);
                timer = 0f;
                xrRig.transform.position = new Vector3(-25.266f, 6.283f, 7.76f);
                redLightStart = false;
                isRedLight = false;
                redLightDone = true;
                goldCup.SetActive(true);
                Instantiate(Fireworks, new Vector3(entranceGuard.transform.position.x, entranceGuard.transform.position.y + 1.5f, entranceGuard.transform.position.z), Quaternion.identity);
            }
        }

        // marble game
        if(marbleStart)
        {
            if (marble.transform.position.y <= .75f)
            {
                marble.transform.position = new Vector3(52.22f, 5.006f, -7.597f);
                timer = 0f;
            }
            if (xrRig.transform.position.y <= 3f)
            {
                xrRig.transform.position = new Vector3(53.462f, 5.565f, -6.467f);
            }
            if (marble.transform.position.y < 3f && marble.transform.position.y > .5f)
            {
                timer += Time.deltaTime;
                if (timer >= 2f)
                {
                    marbleButton.SetActive(true);
                    marbleGame.SetActive(false);
                    marble.SetActive(false);
                    xrRig.transform.position = new Vector3(-25.266f, 6.283f, 7.76f);
                    marbleStart = false;
                    timer = 0f;
                    marbleDone = true;
                    bronzeCup.SetActive(true);
                    Instantiate(Fireworks, new Vector3(entranceGuard.transform.position.x, entranceGuard.transform.position.y + 1.5f, entranceGuard.transform.position.z), Quaternion.identity);
                }
            }
        }

        // jump puzzle game
        if(jumpPuzzleStart)
        {
            if (xrRig.transform.position.y <= 4f)
            {
                xrRig.transform.position = new Vector3(1.237009f, 5.13f, 24.614f);
            }

            if (xrRig.transform.position.z >= 37f)
            {
                jumpPuzzleButton.SetActive(true);
                jumpPuzzleGame.SetActive(false);
                xrRig.transform.position = new Vector3(-25.266f, 6.283f, 7.76f);
                jumpPuzzleStart = false;
                jumpPuzzleDone = true;
                silverCup.SetActive(true);
                Instantiate(Fireworks, new Vector3(entranceGuard.transform.position.x, entranceGuard.transform.position.y+1.5f, entranceGuard.transform.position.z), Quaternion.identity);
            }
            if(xrRig.transform.position.x > 1.342f && xrRig.transform.position.z > 27.92f && xrRig.transform.position.z < 29.64f && jumpPlatforms[0] == 0)
            {
                nearRightDrop.Play("NearRightDropPlat");
            }
            if (xrRig.transform.position.x < 1.342f && xrRig.transform.position.z > 27.92f && xrRig.transform.position.z < 29.64f && jumpPlatforms[1] == 0)
            {
                nearLeftDrop.Play("NearLeftDropPlat");
            }
            if (xrRig.transform.position.x > 1.342f && xrRig.transform.position.z > 31.187f && xrRig.transform.position.z < 32.658f && jumpPlatforms[2] == 0)
            {
                middleRightDrop.Play("MiddleRightDropPlat");
            }
            if (xrRig.transform.position.x < 1.342f && xrRig.transform.position.z > 31.187f && xrRig.transform.position.z < 32.658f && jumpPlatforms[3] == 0)
            {
                middleLeftDrop.Play("MiddleLeftDropPlat");
            }
            if (xrRig.transform.position.x > 1.342f && xrRig.transform.position.z > 34.022f && xrRig.transform.position.z < 35.569f && jumpPlatforms[4] == 0)
            {
                farRightDrop.Play("FarRightDropPlat");
            }
            if (xrRig.transform.position.x < 1.342f && xrRig.transform.position.z > 34.022f && xrRig.transform.position.z < 35.569f && jumpPlatforms[5] == 0)
            {
                farLeftDrop.Play("FarLeftDropPlat");
            }
        }
        
        // game over controls
        if(redLightDone && marbleDone && jumpPuzzleDone)
        {
            menuCube.SetActive(true);
            if (Physics.Raycast(rayPointer, out hit, maxRayDistance, ~excludeLayers))
            {
                if (hit.transform.gameObject.tag == "QuitCube")
                {
                    if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                    {
                        Application.Quit();
                    }
                }
                if (hit.transform.gameObject.tag == "RestartCube")
                {
                    if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                    {
                        SceneManager.LoadScene("Final");
                    }
                }
            }
        }
        
            // raycast interaction controls

            if (Physics.Raycast(rayPointer, out hit, maxRayDistance, ~excludeLayers))
        {
            if (hit.transform.gameObject.tag == "RedLight")
            {
                if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                {
                    xrRig.transform.position = new Vector3(-9.296908f, 3.703096f, -22.23538f);
                    xrRig.transform.rotation = new Quaternion(0, 90, 0, 0);
                }
            }
            if (hit.transform.gameObject.tag == "PlayRedLight")
            {
                if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                {
                    redLightGame.SetActive(true);
                    redLightButton.SetActive(false);
                    redLightStart = true;
                    timer = 0f;
                    xrRig.transform.hasChanged = false;
                }
            }
            if (hit.transform.gameObject.tag == "Marble")
            {
                if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                {
                    xrRig.transform.position = new Vector3(53.462f, 5.565f, -6.467f);

                }
            }
            if (hit.transform.gameObject.tag == "PlayMarble")
            {
                if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                { 

                    xrRig.transform.position = new Vector3(53.462f, 5.565f, -6.467f);
                    marble.transform.position = new Vector3(52.22f, 5.006f, -7.597f);
                    marbleStart = true;
                    marble.SetActive(true);
                    marbleGame.SetActive(true);
                    marbleButton.SetActive(false);
                    timer = 0f;
                }
            }
            if(hit.transform.gameObject.tag == "JumpPuzzle")
            {
                if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                {
                    xrRig.transform.position = new Vector3(1.237009f, 5.13f, 24.614f);
                }
            }
            if(hit.transform.gameObject.tag == "PlayJumpPuzzle")
            {
                if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                {
                    xrRig.transform.position = new Vector3(1.237009f, 5.13f, 24.614f);
                    jumpPuzzleGame.SetActive(true);
                    jumpPuzzleButton.SetActive(false);
                    int arrayElement = 0;
                    UnityEngine.Random.seed = System.DateTime.Now.Millisecond;
                    for (int i = 0; i < 3; i++)
                    {
                        if (UnityEngine.Random.Range(0,2) == 0)
                        {
                            jumpPlatforms[arrayElement] = 1;
                        }
                        else
                        {
                            jumpPlatforms[arrayElement + 1] = 1;
                        }
                        arrayElement += 2;
                    }
                    if(jumpPlatforms[0] == 0)
                    {
                        nearRightPlatform.enabled = false;
                    }
                    if (jumpPlatforms[1] == 0)
                    {
                        nearLeftPlatform.enabled = false;
                    }
                    if (jumpPlatforms[2] == 0)
                    {
                        middleRightPlatform.enabled = false;
                    }
                    if (jumpPlatforms[3] == 0)
                    {
                        middleLeftPlatform.enabled = false;
                    }
                    if (jumpPlatforms[4] == 0)
                    {
                        farRightPlatform.enabled = false;
                    }
                    if (jumpPlatforms[5] == 0)
                    {
                        farLeftPlatform.enabled = false;
                    }
                    jumpPuzzleStart = true;
                }
            }
            if (hit.transform.gameObject.tag == "OpenDoor")
            {
                if (device.TryGetFeatureValue(CommonUsages.triggerButton, out triggerValue) && triggerValue)
                {
                    openDoor.Play("OpenDoor");
                    doorOpenCube.SetActive(false);
                    introCube.SetActive(false);
                    giHunCube.SetActive(true);
                }
            }
        }
    }
}
