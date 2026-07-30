#include "Common.h"

void AddSC_mod_dynamicobject_duration();

class DynamicObjectDurationLoader : public AddonScript
{
public:
    DynamicObjectDurationLoader()
        : AddonScript("mod_dynamicobject_duration")
    {
    }

    void OnAfterConfigLoad(bool /*reload*/) override
    {
        LOG_INFO("module", "[{}] Loaded.", DynamicObjectDuration::MODULE_NAME);
    }
};

void Addmod_dynamicobject_durationScripts()
{
    new DynamicObjectDurationLoader();

    AddSC_mod_dynamicobject_duration();
}