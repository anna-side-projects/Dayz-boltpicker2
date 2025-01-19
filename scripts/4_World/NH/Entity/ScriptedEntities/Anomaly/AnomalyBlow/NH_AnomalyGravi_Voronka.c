modded class NH_AnomalyGravi_VoronkaTrigger : NH_AnomalyBlowBase
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