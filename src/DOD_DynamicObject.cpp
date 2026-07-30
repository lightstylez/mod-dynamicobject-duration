#include "DOD_Common.h"

class DODDynamicObjectScript : public DynamicObjectScript
{
public:
    DODDynamicObjectScript() : DynamicObjectScript("DODDynamicObjectScript")
    {
    }

    void OnDynamicObjectUpdate(DynamicObject* dynObj, uint32 diff) override
    {
        (void)diff;

        if (!dynObj)
            return;

        LOG_INFO("server.loading",
            "[DOD] SpellId={} Duration={}",
            dynObj->GetSpellId(),
            dynObj->GetDuration());
    }
};

void AddSC_DOD_DynamicObject()
{
    new DODDynamicObjectScript();
}