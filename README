# HouseAuth
House Auth is an implementation of secure_house. 
House auth is designed to only allow users with valid keys into the home.
To initialize house auth an owner, as well as an initial set of keys must be passed to the program at start up.
To enter a house the user must 
* INSERT KEY <user_name> <key>
* TURN KEY <user_name>
* ENTER HOUSE <user_name>

Other users can interface with the house without interrupting other users from entering the house. This means that house auth can take multiple instructions between a user inserting the key and turning the key. However it should be noted that the house can only have one key inserted at a time. Meaning that if another user inserts his/her key, then the previous user will not be able to continue his/her workflow. 

House Auth has functions related to who is in the house and exiting the house. While entering is regulated, anyone in the house may exit at any time.
* WHO'S INSIDE?
* LEAVE HOUSE <user_name>

The owner of the house can also change the locks. However, the owner must be inside the house to do so. No other users can change locks. 
* CHANGE LOCKS <user_name> <key_1> <key_2> ... <key_n>

The responsibility of the workflow is split between three classes:
* InstructionInterpreter
* House
* Lock

## Instruction Interpreter 
The Instruction is responsible for taking input and verifying that it is a valid set of instructions. It also checks some basic preconditions to make sure that instructions are formatted correctly. Instruction Interpreter then passes the instructions on to the house. 

## House
House's main function is to keep track of who is inside as well as report what happens at the door. All messaging about access control is handled by the house. House also Knows who's the owner and will not let anyone else change locks.

## Lock
Lock keeps track of who is inserting keys as well as which keys are valid. Lock also has a special access for Firefighters. Lock tells house when a valid key has been turned as well as keeping track of the user who inserted it and the user who turned it. 
