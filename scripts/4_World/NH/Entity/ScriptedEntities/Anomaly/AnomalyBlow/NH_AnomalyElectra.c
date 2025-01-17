modded class NH_AnomalyElectraTrigger extends NH_AnomalyBlowBase
{
    override void InitHitTargets()
    {
        InsertHitTarget(BlobBolt);
    }

    void OnBlobBoltHit(Object obj)
    {
        obj.Delete();
    }
}