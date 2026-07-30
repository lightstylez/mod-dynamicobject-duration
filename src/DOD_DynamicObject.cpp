#include "DOD_Common.h"

class DODDynamicObjectScript : public DynamicObjectScript
{
public:
    DODDynamicObjectScript() : DynamicObjectScript("DODDynamicObjectScript")
    {
    }

    void OnUpdate(DynamicObject* dynamicObject, uint32 diff) override
    {
        (void)diff;

        if (!dynamicObject)
            return;

        LOG_INFO("server.loading",
            "[{}] DynamicObject spell {} duration {}",
            DOD::MODULE_NAME,
            dynamicObject->GetSpellId(),
            dynamicObject->GetDuration());
    }
};

void AddSC_DOD_DynamicObject()
{
    new DODDynamicObjectScript();
}