using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class MenuManager : MonoBehaviour
{

	IEnumerator Scene(int scene)
	{
		yield return new WaitForSeconds(0.5f);

		SceneManager.LoadScene(scene, LoadSceneMode.Single);
	}

	public void ExitGame()
	{
		Application.Quit();
	}

	public void StartGame(int difficulty)
	{
		GameManager.difficulty = difficulty;

		StartCoroutine(Scene(1));
	}
}
