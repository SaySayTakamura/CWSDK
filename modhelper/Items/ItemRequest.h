#pragma once

#include <iostream>
#include <string>

#include <cwsdk.h>

namespace modhelper
{
	//Defines a TYPE of request to be Sent
	typedef enum REQUEST_TYPE
	{
		WEAPON = 0, //Request a weapon from a mod 
		CONSUMABLE, //Requests a Consumable item from a mod
		UPDATE, //Updates the Modloader's ItemManager database
		UNKNOWN, //In case the user provides only a name;
	};

	//Shows how our request has been handled.
	/*
	*	-1 - Failed
	*	1 - Success
	*	2 - Waiting (Might never happen tho)
	*/
	typedef struct REQUEST_STATUS
	{
		int CODE; //Status code, there's a gloassary of those above this comment TwT
		std::string Description; //In case of any error this is merely a "std::exception" clone but contains an id and if that represents an error it will fill this field as well.
	};

	class ItemRequest
	{
	private:
		REQUEST_TYPE RequestType; //Type of request we are making, will be Unknown in case we use Constructor #1
		std::string ModName; //Name of the mod we will be requesting item (if the name of the mod is the same of the Request Emitter, it will return "FAILED" as status;
		std::string ItemName; //ItemName to search, you can't search withou it... Well you can don't know if it will work lol.

	public:
		ItemRequest() { RequestType = UNKNOWN; ModName = "Undefined"; ItemName = "Undefined"; }
		ItemRequest(std::string itemName) { RequestType = UNKNOWN; ModName = "Undefined"; ItemName = itemName; }
		ItemRequest(std::string itemName, std::string modName) { ItemName = itemName; ModName = modName; }
		ItemRequest(std::string itemName, std::string modName, REQUEST_TYPE requestType) { ItemName = itemName; ModName = modName; RequestType = requestType; }
	};

	//Draft CLASS
	//Request Manager
	class RequestManager
	{
	private:
		std::vector<ItemRequest> rm_QUEUE; //Hold a QUEUE of pending REQUESTS assigned to an ID
		
		int rm_RequestId; //The current request to be tracked

		std::pair<REQUEST_STATUS, std::pair<modhelper::ItemData*, cube::Item*>> rm_CurrentResult; //Hold the STATUS and the Item, of the current request result to be handled.

	public:
		//Default Constructor, don't worry in calling it UwU
		RequestManager() { rm_QUEUE = {}; rm_CurrentResult = {}; rm_RequestId = 0; }


		//Resets the current results and increases the ID.
		void Dispatch() 
		{
			rm_CurrentResult.first.CODE = 2;
			rm_CurrentResult.second = { nullptr, nullptr };

			if (rm_QUEUE.size() > 1)
			{
				rm_RequestId++;
			}

		}
		//Pushes a Request to the Queue to be handled
		void Add(ItemRequest requestData)
		{
			rm_QUEUE.push_back(requestData);
		}

		//Use as wish, normally only used by the MODLOADER to track the CURRENT request to be handled by it.
		ItemRequest GetRequest()
		{
			return rm_QUEUE[rm_RequestId];
		}

		//Returns the current result, nice to have and keep track of how your requests is going
		//if(request_manager.GetCurrentResult().first.code == 2){ShowMessage("Waiting for an item UwU");}
		std::pair<REQUEST_STATUS, std::pair<modhelper::ItemData*, cube::Item*>> GetCurrentResult() { return rm_CurrentResult; }

	};

	static inline ItemRequest CreateItemRequest(std::string itemName) { return ItemRequest(itemName); }
	static inline ItemRequest CreateItemRequest(std::string itemName, std::string modName) { return ItemRequest(itemName, modName); }
	static inline ItemRequest CreateItemRequest(std::string itemName, std::string modName, REQUEST_TYPE requestType) { return ItemRequest(itemName, modName, requestType); }
}