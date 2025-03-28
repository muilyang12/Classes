using UnityEngine;
using System;

public class RaycastManager : MonoBehaviour
{
    private static Action<RaycastHit?> raycastHitEvents;

    public static void RegisterRaycastHitEvent(Action<RaycastHit?> newEvent)
    {
        raycastHitEvents += newEvent;
    } 

    public static void UnregisterRaycastHitEvent(Action<RaycastHit?> targetEvent)
    {
        raycastHitEvents -= targetEvent;
    }

    // ==================================================

    private LineRenderer lineRenderer;
    private Camera mainCamera;

    private GameObject lastHighlightedObject;

    public float maxDistance = 50f;

    void Start()
    {
        lineRenderer = GetComponent<LineRenderer>();
        lineRenderer.GetComponent<LineRenderer>().startWidth = 0.2f;
        lineRenderer.GetComponent<LineRenderer>().endWidth = 0.2f;

        mainCamera = Camera.main;
    }

    void Update()
    {
        Ray ray = new Ray(mainCamera.transform.position, mainCamera.transform.forward);
        RaycastHit hit;

        Vector3 startPoint = ray.origin + new Vector3(0, -0.3f, 0);
        Vector3 endPoint;

        if (Physics.Raycast(ray, out hit, maxDistance))
        {
            endPoint = hit.point;

            raycastHitEvents?.Invoke(hit);
        }
        else
        {
            endPoint = ray.origin + ray.direction * maxDistance;

            raycastHitEvents.Invoke(null);
        }

        lineRenderer.SetPosition(0, startPoint);
        lineRenderer.SetPosition(1, endPoint);
    }
}
