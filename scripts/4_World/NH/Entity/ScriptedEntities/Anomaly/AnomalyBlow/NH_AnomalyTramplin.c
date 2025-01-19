modded class NH_AnomalyTramplinTrigger : NH_AnomalyBlowBase
{
    override void InitHitTargets()
    {
        super.InitHitTargets();
        InsertHitTarget(BlobBolt);
    }

    void OnBlobBoltHit(Object obj)
    {
        obj.Delete();
    }
}