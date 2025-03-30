using UnityEngine;

public class ObjectMenuManager : MonoBehaviour
{
    private bool isEnabled = true;

    public GameObject objectMenu;
    public GameObject character;

    private Camera mainCamera;
    private GameObject currentPointedObject;
    private GameObject menuTargetObject;

    void Start()
    {
        Hide();

        mainCamera = Camera.main;

        SettingMenuController.RegisterSettingMenuOpenEvent(TurnOffController, TurnOnController);
        RaycastManager.RegisterRaycastHitEvent(HandleRaycastHit);
    }

    void OnDestroy()
    {
        SettingMenuController.UnregisterSettingMenuOpenEvent(TurnOffController, TurnOnController);
        RaycastManager.UnregisterRaycastHitEvent(HandleRaycastHit);
    }

    private void HandleRaycastHit(RaycastHit? hit)
    {
        if (!isEnabled)
            return;

        if (hit.HasValue && hit.Value.collider.gameObject.CompareTag("ObjectMenuTarget"))
        {
            currentPointedObject = hit.Value.collider.gameObject;
        }
        else
            currentPointedObject = null;
    }

    void Update()
    {
        // When the "X" button is pressed.
        if (Input.GetButtonDown("js1") || Input.GetButtonDown("js2") || Input.GetKeyDown(KeyCode.X))
        {
            if (currentPointedObject != null)
                Toggle();
            else
                Hide();
        }
    }

    public GameObject GetMenuTargetObject()
    {
        return menuTargetObject;
    }

    public void Toggle()
    {
        if (objectMenu.activeSelf)
            Hide();
        else
            Show();
    }

    private void Show()
    {
        objectMenu.SetActive(true);

        DisableCharacterMovement();

        menuTargetObject = currentPointedObject;

        (Vector3 menuPosition, Quaternion menuRotation) = CalculateMenuPositionRotation();

        objectMenu.transform.SetPositionAndRotation(menuPosition, menuRotation);
    }

    private void Hide()
    {
        objectMenu.SetActive(false);

        EnableCharacterMovement();

        menuTargetObject = null;
    }

    private (Vector3, Quaternion) CalculateMenuPositionRotation()
    {
        float objectHeight = 0f;

        Collider collider = currentPointedObject.GetComponent<Collider>();

        if (collider != null)
        {
            objectHeight = collider.bounds.size.y;
        }
        else
        {
            objectHeight = 1.5f;
        }

        Vector3 menuPosition = currentPointedObject.transform.position + new Vector3(0, objectHeight + 0.2f, 0);

        Vector3 vectorFromCameraToMenu = mainCamera.transform.position - menuPosition;

        Quaternion menuRotation = Quaternion.LookRotation(-vectorFromCameraToMenu);

        return (menuPosition, menuRotation);
    }

    private void EnableCharacterMovement()
    {
        CharacterMovement charMovement = character.GetComponent<CharacterMovement>();

        if (charMovement != null)
            charMovement.enabled = true;
    }

    private void DisableCharacterMovement()
    {
        CharacterMovement charMovement = character.GetComponent<CharacterMovement>();

        if (charMovement != null)
            charMovement.enabled = false;
    }


    private void TurnOnController()
    {
        isEnabled = true;
    }

    private void TurnOffController()
    {
        Hide();

        isEnabled = false;
    }
}