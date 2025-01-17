modded class NH_AnomalyTramplinTrigger extends NH_AnomalyBlowBase
{
    override void InitHitTargets()
    {
        InsertHitTarget(BlobBolt);
    }

    void OnBlobBoltHit(Object obj)
    {
        obj.DeleteSafe();
    }
}