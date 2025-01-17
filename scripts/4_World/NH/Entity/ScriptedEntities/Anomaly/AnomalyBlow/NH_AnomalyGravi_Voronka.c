modded class NH_AnomalyGravi_VoronkaTrigger extends NH_AnomalyBlowBase
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