modded class NH_AnomalyGravi_Voronka extends NH_AnomalyBlowBase
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