modded class NH_AnomalyElectraTrigger : NH_AnomalyBlowBase
{
    override void InitHitTargets()
    {
        super.InitHitTargets();
        PRINT("ELECTRA BOLT INIT");
        InsertHitTarget(BlobBolt);
    }

    void OnBlobBoltHit(Object obj)
    {
        Print("BOLT HIT");
        obj.Delete();
    }
}