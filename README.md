
# Catan Game Implementation

This project implements the classic board game Catan using C++. The implementation includes several classes that represent the different components of the game, such as vertices, edges, tiles, players, and various types of cards. Below is an overview of the classes, their attributes, and methods.

## Classes

### Vertex

Represents a vertex in the game board, which can hold settlements or cities and can be connected by roads.

**Attributes:**
- `number`: The identifier of the vertex.
- `settlement`: Indicates if there is a settlement on this vertex.
- `city`: Indicates if there is a city on this vertex.
- `roads`: Roads connected to this vertex.
- `resources`: Resources associated with this vertex.
- `adjacentTiles`: Tiles adjacent to this vertex.

**Methods:**
- `getNumber()`: Returns the number of the vertex.
- `getColorVertex()`: Returns the color of the vertex.
- `setColor(Color)`: Sets the color of the vertex.
- `isEmpty()`: Checks if the vertex is empty.
- `buildSettlement(Color)`: Builds a settlement on the vertex.
- `removeSettlement()`: Removes a settlement from the vertex.
- `buildCity(Color)`: Builds a city on the vertex.
- `ColorToString(Color)`: Converts color to a string.
- `buildRoad(Vertex, Vertex, Color)`: Builds a road from this vertex to another.
- `getRoads()`: Returns the roads connected to this vertex.
- `getSettlement()`: Returns the settlement on this vertex.
- `getCity()`: Returns the city on this vertex.
- `hasSettlement()`: Checks if the vertex has a settlement.
- `hasCity()`: Checks if the vertex has a city.
- `getResources()`: Returns the resources of the vertex.
- `addResource(Resource)`: Adds a resource to the vertex.
- `printResources()`: Prints the resources of the vertex.
- `addAdjacentTile(int)`: Adds an adjacent tile to the vertex.
- `getAdjacentTiles()`: Returns the adjacent tiles.

### Tile

Represents a tile in the game board, which can produce resources.

**Attributes:**
- `vertices`: Vertices of the tile.
- `edges`: Edges of the tile.
- `resource`: Resource type of the tile.
- `number`: Number on the tile for dice rolls.

**Methods:**
- `getVertices()`: Returns the vertices of the tile.
- `getEdges()`: Returns the edges of the tile.
- `getResource()`: Returns the resource of the tile.
- `getNumber()`: Returns the number of the tile.
- `getResourceString()`: Returns the resource as a string.

### Settlement

Represents a settlement in the game, which can be built on vertices.

**Attributes:**
- `owner`: Owner of the settlement.
- `location`: Location of the settlement.

**Methods:**
- `getOwner()`: Returns the owner of the settlement.
- `getLocation()`: Returns the location of the settlement.

### Road

Represents a road in the game, which connects two vertices.

**Attributes:**
- `owner`: Owner of the road.
- `start`: Starting vertex of the road.
- `end`: Ending vertex of the road.

**Methods:**
- `getOwner()`: Returns the owner of the road.
- `getStart()`: Returns the starting vertex of the road.
- `getEnd()`: Returns the ending vertex of the road.

### Resource

An enum class representing the various resources in the game.

**Values:**
- Wood, Brick, Wool, Oats, Iron, Desert.

**Methods:**
- `resourceToString()`: Converts the resource enum to a string.

### Card

Represents a card in the game, which can be a development card or a promotion card.

**Attributes:**
- `type`: Type of the card.
- `subtype`: Subtype of the card.
- `used`: Indicates if the card has been used.

**Methods:**
- `use(Player&, Catan&)`: Uses the card, affecting the player or the game.

### Player

Represents a player in the game.

**Attributes:**
- `name`: Name of the player.
- `resources`: Resources held by the player.
- `settlements`: Settlements owned by the player.
- `cities`: Cities owned by the player.
- `roads`: Roads owned by the player.
- `cards`: Cards held by the player.

**Methods:**
- `getName()`: Returns the name of the player.
- `setResource(Resource, int)`: Sets the amount of a resource.
- `getResource(Resource)`: Returns the amount of a resource.
- `addSettlement(Vertex)`: Adds a settlement.
- `addCity(Vertex)`: Adds a city.
- `addRoad(Road)`: Adds a road.
- `addCard(Card)`: Adds a card.
- `useCard(Card)`: Uses a card.
- `tradeResource(Player&, Resource, int, Resource, int)`: Trades resources with another player.
- `tradeCard(Player&, Card, Card)`: Trades cards with another player.
- `buyPromotionCard()`: Buys a promotion card.
- `removeResource(Resource, int)`: Removes a specified amount of a resource.
- `addResource(Resource, int)`: Adds a specified amount of a resource.
- `removeCard(Card)`: Removes a specified card.
- `getAllResources()`: Returns all resources held by the player.
- `getAllCards()`: Returns all cards held by the player.

### Board

Represents the game board, which consists of vertices, edges, and tiles.

**Attributes:**
- `vertices`: Vertices of the board.
- `edges`: Edges of the board.
- `tiles`: Tiles of the board.

**Methods:**
- `initializeBoard()`: Initializes the board with vertices, edges, and tiles.
- `printBoard()`: Prints the board.
- `getVertex(int)`: Returns a vertex by its number.
- `getAllTiles()`: Returns all tiles on the board.

### Catan

Represents the Catan game itself, managing the board, players, and gameplay.

**Attributes:**
- `board`: The game board.
- `players`: The players in the game.

**Methods:**
- `initializeGame()`: Initializes the game.
- `startGame()`: Starts the game.
- `getPlayer1()`, `getPlayer2()`, `getPlayer3()`: Returns the respective player.
- `getBoard()`: Returns the game board.

