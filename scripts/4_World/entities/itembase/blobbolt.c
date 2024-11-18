class BlobBolt : Item_Base
{
    override void ThrowPhysically(DayZPlayer player, vector force, bool collideWithCharacters = true)
    {
        super.ThrowPhysically(player,force,true);
        sleep 5;
        this.DeleteSafe();
    }
}