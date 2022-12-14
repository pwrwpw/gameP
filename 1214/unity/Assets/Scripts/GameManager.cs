using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using System.Collections;

public class GameManager : MonoBehaviour
{
	public static int difficulty;
	private string[] difficultyNames = { "NaN", "Easy", "Medium", "Hard" };

	private float score;
	public Text scoreUI;
	private int highscore;
	public Text highscoreUI;

	public PlayerMovement movement;

	public GameObject obstaclePrefab;
	public Transform obstacles;
	public int obstacleStartX = 100;

	public GameObject deathOverlayUI;

	bool isPause = false;


	IEnumerator DeathOverlay()
	{
		yield return new WaitForSeconds(1.0f);

		deathOverlayUI.SetActive(true);

		yield return new WaitForSeconds(0.5f);
	}

	IEnumerator Scene(int scene)
	{
		yield return new WaitForSeconds(0.5f);

		SceneManager.LoadScene(scene, LoadSceneMode.Single);
	}

	public void SwitchScene(int scene)
	{
		StartCoroutine(Scene(scene));
	}

	public void Death()
	{
		CancelInvoke("Spawn");

		FindObjectOfType<PlayerMovement>().enabled = false;

		foreach (Transform obstacle in obstacles)
		{
			obstacle.gameObject.GetComponent<ObstacleMovement>().enabled = false;
		}

		UpdateHighscore();
		highscoreUI.text = difficultyNames[difficulty] + " highscore: " + highscore;

		obstaclePrefab.GetComponent<ObstacleMovement>().force = 30;

		StartCoroutine(DeathOverlay());
	}

	private void UpdateHighscore()
	{
		highscore = PlayerPrefs.GetInt("Highscore" + difficulty);

		if (score > highscore)
		{
			highscore = (int)score;
			PlayerPrefs.SetInt("Highscore" + difficulty, highscore);
		}
	}

	private void Spawn()
	{
		int i;	
		for (i = -7; i < 7; i += 7)
		{
			Instantiate(obstaclePrefab,
			            new Vector3(Mathf.Floor(Random.Range(i, i + 7)), 1, obstacleStartX),
			            Quaternion.Euler(0.0f,180.0f,0.0f), obstacles);
		}
	}

	private void Update()
	{
		if (FindObjectOfType<PlayerMovement>().enabled)
		{
			score += Time.deltaTime * 10;
			scoreUI.text = "Score: " + (int)score;
			obstaclePrefab.GetComponent<ObstacleMovement>().force += Time.deltaTime;
		}
		if (Input.GetKey("r"))
		{
			SwitchScene(1);
			return;
		}

		if (Input.GetKeyDown(KeyCode.Escape))
		{
			if(isPause == false){
				Time.timeScale = 0f;
				isPause = true;
			}
			else if(isPause == true){
				Time.timeScale = 1f;
				isPause = false;
			}

		}
	}

	private void Start()
	{
		// 난이도 조절
		InvokeRepeating("Spawn", 1f, 1f / difficulty);
	}
}
