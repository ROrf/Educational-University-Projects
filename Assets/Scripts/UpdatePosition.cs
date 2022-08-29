using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class UpdatePosition : MonoBehaviour
{
    int lives = 3;
    int score = 0;
    Vector3 mousePosition;
    public float movespeed = 0.1f;
    Rigidbody2D rb;
    Vector2 position = new Vector2(0f, 0f);

    [Header("Set in Inspector")]
    public GameObject[] lifeSprites;
    public GameObject ship;
    public GameObject button;
    public int levelNum = 0;
    public Vector3 origin;
    public ParticleSystem explosion;
    public ParticleSystem playerExplosion;
    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        score = PlayerPrefs.GetInt("Score");
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
        position = Vector2.Lerp(transform.position, mousePosition, movespeed);
        rb.MovePosition(position);
        GameObject[] enemies = GameObject.FindGameObjectsWithTag("Empire");
        if (enemies.Length == 0)
        {
            PlayerPrefs.SetInt("Score", score+ 500);
            switch (levelNum)
            {
                case 1:
                    PlayerPrefs.SetInt("Highest", 1);
                    SceneManager.LoadScene("_Level_2");
                    break;
                case 2:
                    PlayerPrefs.SetInt("Highest", 2);
                    SceneManager.LoadScene("_Level_3");
                    break;
                case 3:
                    PlayerPrefs.SetInt("Highest", 3);
                    SceneManager.LoadScene("_Level_4");
                    break;
                default:
                    PlayerPrefs.SetInt("Highest", 4);
                    SceneManager.LoadScene("_End_Screen");
                    break;
            }
            //SceneManager.LoadScene("_End_Screen");
        }
    }

    void LateUpdate()
    {
        if (transform.position != Camera.main.ScreenToWorldPoint(Input.mousePosition))
        {
            Vector3 difference = Camera.main.ScreenToWorldPoint(Input.mousePosition) - transform.position;
            difference.Normalize();
            float rotationZ = Mathf.Atan2(difference.y, difference.x) * Mathf.Rad2Deg;
            transform.rotation = Quaternion.Euler(0f, 0f, rotationZ + 180f);
        }
    }

    void OnCollisionEnter2D(Collision2D coll)
    {
        GameObject other = coll.gameObject;
        if(other.tag == "Empire")
        {
            ParticleSystem explodeEffect = Instantiate(explosion, new Vector3(other.transform.position.x, other.transform.position.y, -5f), Quaternion.identity);
            explodeEffect.Play();
            score += 100;
            PlayerPrefs.SetInt("Score", score);
            Destroy(other);
        }
        if (other.tag == "Environment")
        {
            ParticleSystem explodeEffect = Instantiate(playerExplosion, new Vector3(this.transform.position.x, this.transform.position.y, -5f), Quaternion.identity);
            explodeEffect.Play();
            lives--;
            lifeSprites[lives].SetActive(false);
            ship.transform.position = origin;
            ship.SetActive(false);
            button.SetActive(true);
            if (lives == 0)
            {
                Destroy(gameObject);
                PlayerPrefs.SetInt("Score", score);
                SceneManager.LoadScene("_End_Screen");
            }
        }
        if(other.tag == "Collectable")
        {
            Destroy(other);
            GameObject unlockSwitch = GameObject.FindGameObjectWithTag("Unlock");
            unlockSwitch.GetComponent<SpriteRenderer>().color = new Color(23 / 255f, 159 / 255f, 34 / 255f, 1);
        }
        if(other.tag == "Unlock") {
            Color desiredColor = new Color(23 / 255f, 159 / 255f, 34 / 255f, 1);
            if(other.GetComponent<SpriteRenderer>().color == desiredColor)
            {
                GameObject forceField = GameObject.FindGameObjectWithTag("Force Field");
                forceField.SetActive(false);
                other.GetComponent<SpriteRenderer>().color = new Color(118 / 255f, 118 / 255f, 118 / 255f, 1);
            }
        }
    }
}