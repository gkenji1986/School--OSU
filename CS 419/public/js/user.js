User = function () {

    this.gold = 500;
    this.towers = {};
    this.lives = 10;
};

User.prototype.Make_Tower = function (coordinate, type) {

    var pos = g.map.position(coordinate);
    
    pos.tower = new Tower(this, coordinate, type, 0);
    if ((this.gold - pos.tower.cost) >= 0)
    {
        pos.tower.id = _.uniqueId('tower_');
        this.towers[pos.tower.id] = pos.tower;

        this.gold = this.gold - pos.tower.cost;

        return pos.tower;
    }

    else
    {
        return 0;
    }

}

User.prototype.Sell_Tower = function (tower) {
    var pos = g.map.position(tower.coordinate);
    pos.tower = null;

    delete this.towers[tower.id];

    this.gold = this.gold + tower.sell;
}