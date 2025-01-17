modded class NH_AnomalyBaseTrigger extends Trigger 
{
    override void InitHitTargets()
    {
        super.InitHitTargets();
        InsertHitTarget(BlobBolt);
    }
}