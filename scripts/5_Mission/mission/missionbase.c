modded class MissionBase
{
	autoptr CF_InputBindings inputBindings;
	string modname;
	string boltInput;
	string itemClass;
	
	override void OnInit()
	{
		super.OnInit();
		boltInput = "UAGrabBolt";
		itemClass="BlobBolt";
		modname = "UnderbarrelCigarette";
		inputBindings = new CF_InputBindings(this);
		inputBindings.Bind("checkBoltInput", boltInput, true);
		GetRPCManager().AddRPC(modname, "spawnBoltRPC",this, SingleplayerExecutionType.Both);
		Print("Init done");
	}
	
	void checkBoltInput(UAInput uain)
	{
		if(uain.LocalHold() && PlayerBase.Cast(GetGame().GetPlayer()).GetHumanInventory().GetEntityInHands() == NULL && GetGame().GetUIManager().GetMenu() == NULL)
		{
            spawnBolt();
        }
	}
	void spawnBoltRPC(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		Param1<string> data;
		
		if(!ctx.Read(data)) return;
		PlayerBase player;
		BlobBolt bolt;
		if(type == CallType.Server)
		{
			Print("Player  =  " + sender.GetPlayer());
            player = PlayerBase.Cast(sender.GetPlayer());
			if(!player)
				player = GetGame().GetPlayer();
            if(player.GetHumanInventory().GetEntityInHands() == null) {
			    bolt = PlayerBase.Cast(sender.GetPlayer()).GetHumanInventory().CreateInHands(itemClass);
				bolt.SetPlayer(player);
				bolt.Init();
			}
		}
		else
		{
            player = GetGame().GetPlayer();
            if(player.GetHumanInventory().GetEntityInHands() == null) {
			    bolt = player.GetHumanInventory().CreateInHands(itemClass);
				bolt.SetPlayer(player);
				bolt.Init();
			}
		}
	}

    void spawnBolt()
	{
		GetRPCManager().SendRPC(modname, "spawnBoltRPC",new Param1<string>(itemClass));
	}
}