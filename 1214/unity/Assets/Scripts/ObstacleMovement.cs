using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstacleMovement : MonoBehaviour
{
	public float time;
	public float force = 30;

	private void OnCollisionEnter(Collision collision)
	{
		switch (collision.gameObject.tag)
		{
			case "Player":
				GetComponent<AudioSource>().Play();
				FindObjectOfType<GameManager>().Death();
				break;
			case "ObstacleWall":
				Destroy(gameObject);
				break;
		}
	}

	private void Update()
	{
		GetComponent<Rigidbody>().AddForce(0f, 0f, -force);
	}
}
