class BlobBolt extends ItemBase
{
    protected PlayerBase player;

    void SetPlayer(PlayerBase p) {
        this.player = p;
    }
    void Init() {
        ScriptCallQueue queue = GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY);
        queue.CallLater(this.Suicide, 20000, false);
    }
    PlayerBase GetPlayer() {
        return this.player;
    }
    void Suicide()
    {
        if(this.GetPlayer()) {
            if(this.GetPlayer().GetHumanInventory().GetEntityInHands() && this.GetPlayer().GetHumanInventory().GetEntityInHands().GetID() == this.GetID()) {
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.Suicide, 20000, false);
            } else {
                this.DeleteSafe();
            }
        }
    }
}