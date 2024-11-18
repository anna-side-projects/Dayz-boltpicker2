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
		modname = "BoltPicker2";
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
		if(type == CallType.Server)
		{
            PlayerBase player = PlayerBase.Cast(sender.GetPlayer());
            if(player.GetHumanInventory().GetEntityInHands() == null)
			    PlayerBase.Cast(sender.GetPlayer()).GetHumanInventory().CreateInHands(itemClass);
		}
		else
		{
            PlayerBase player = GetGame().GetPlayer();
			Print("Bolts called on client not sure how we got here...");
            if(player.GetHumanInventory().GetEntityInHands() == null)
			    player.GetHumanInventory().CreateInHands(itemClass);
		}
	}

    void spawnBolt()
	{
		GetRPCManager().SendRPC(modname, "spawnBoltRPC",new Param1<string>(itemClass));
	}
}