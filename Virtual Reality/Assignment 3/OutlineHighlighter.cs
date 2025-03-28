using UnityEngine;

public class OutlineHighlighter : MonoBehaviour
{
    private Outline outline;

    void Start()
    {
        outline = GetComponent<Outline>();

        outline.enabled = false;
        outline.OutlineColor = Color.red;

        RaycastManager.RegisterRaycastHitEvent(HandleOutlineHighlight);
    }

    private void OnDestroy()
    {
        RaycastManager.UnregisterRaycastHitEvent(HandleOutlineHighlight);
    }

    private void HandleOutlineHighlight(RaycastHit? hit)
    {
        if (hit.HasValue && hit.Value.collider.gameObject == gameObject)
        {
            HighlightOn();
        } 
        else
        {
            HighlightOff();
        }
    }

    private void HighlightOn()
    {
        outline.enabled = true;
    }

    private void HighlightOff()
    {
        outline.enabled = false;
    }
}
