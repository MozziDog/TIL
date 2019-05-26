using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class PausedMenu : MonoBehaviour {

    public GameObject pauseUI;
    public GameObject GameoverUI;
    private bool paused;
    
	// Use this for initialization
	void Start () {
        paused = false;
        pauseUI.SetActive(false);
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            if (!GameoverUI.activeInHierarchy)
            {
                paused = !paused;
            }
        }

        if (paused == true)
        {
            pauseUI.SetActive(true);
            Time.timeScale = 0;
        }
        else
        {
            pauseUI.SetActive(false);
            Time.timeScale = 1;
        }
	}

    public bool getPaused() {
        return paused;
    }
    
}
