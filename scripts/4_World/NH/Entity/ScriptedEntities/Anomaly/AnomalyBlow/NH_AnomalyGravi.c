modded class NH_AnomalyGraviTrigger : NH_AnomalyBlowBase
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