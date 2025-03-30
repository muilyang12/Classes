using UnityEngine;

public class GrabButtonHandler : MonoBehaviour
{
    public ObjectMenuManager menManager;
    public GameObject grabButton;

    private Camera mainCamera;

    private bool isHovered = false;

    private GameObject grabbedObject;
    private bool isGrabbed = false;

    private bool originalRigidbodyGravity;

    void Start()
    {
        mainCamera = Camera.main;

        RaycastManager.RegisterRaycastHitEvent(HandleRaycastHit);
    }

    void OnDestroy()
    {
        RaycastManager.UnregisterRaycastHitEvent(HandleRaycastHit);
    }

    private void HandleRaycastHit(RaycastHit? hit)
    {
        if (hit.HasValue && hit.Value.collider.gameObject == grabButton)
            isHovered = true;
        else
            isHovered = false;
    }

    void Update()
    {
        // Button "B"
        if (Input.GetButtonDown("js8") || Input.GetButtonDown("js10") || Input.GetKeyDown(KeyCode.B))
        {
            if (!isHovered)
                return;

            if (menManager.GetMenuTargetObject() != null)
            {
                GrabObject();

                menManager.Toggle();
            }
        }

        // Button "A"
        if (Input.GetButtonDown("js8") || Input.GetButtonDown("js10") || Input.GetKeyDown(KeyCode.A))
        {
            if (isGrabbed)
                ReleaseObject();
        }
    }

    private void GrabObject()
    {
        GameObject menuTargetObject = menManager.GetMenuTargetObject();

        grabbedObject = menuTargetObject;
        grabbedObject.transform.SetParent(mainCamera.transform);
        grabbedObject.transform.localPosition = mainCamera.transform.forward * 2f;

        Rigidbody rigidbody = grabbedObject.GetComponent<Rigidbody>();
        if (rigidbody != null)
        {
            originalRigidbodyGravity = rigidbody.useGravity;

            rigidbody.useGravity = false;
        }

        isGrabbed = true;
    }

    private void ReleaseObject()
    {
        grabbedObject.transform.SetParent(null);

        Rigidbody rigidbody = grabbedObject.GetComponent<Rigidbody>();
        if (rigidbody != null)
            rigidbody.useGravity = originalRigidbodyGravity;

        isGrabbed = false;

        grabbedObject = null;
    }
}
