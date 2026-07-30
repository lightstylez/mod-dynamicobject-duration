#include "DOD_Common.h"

class DODDynamicObjectScript : public DynamicObjectScript
{
public:
    DODDynamicObjectScript()
        : DynamicObjectScript("DODDynamicObjectScript")
    {
        LOG_INFO("server.loading", "[DOD] Loaded DynamicObject script");
    }

    void OnUpdate(DynamicObject* dynObj, uint32 /*diff*/) override
    {
        if (!dynObj)
            return;

        switch (dynObj->GetSpellId())
        {
            case 26573:
            case 20116:
            case 20922:
            case 20923:
            case 20924:
            case 27173:
            case 48818:
            case 48819:
                break;

            default:
                return;
        }

        int32 duration = dynObj->GetDuration();

        // Only modify immediately after creation.
        if (duration <= 8000 && duration >= 7900)
        {
            LOG_INFO("server.loading",
                "[DOD] Extending Consecration {} -> 12000",
                duration);

            dynObj->SetDuration(12000);
        }
    }
};

void AddSC_DOD_DynamicObject()
{
    new DODDynamicObjectScript();
}