var Tower = function (player, coordinate, type) {
    //set stats for tower
    _.defaults(this, TOWER[type]);

    this.player = player;
    this.type = type;
    this.coordinate = coordinate;
    this.busy = 0;
}

var TOWER = {

    REINDEER: [
        {
            name: 'Reindeer',
            damage: 5,
            range: 500,
            rate: 2500,
            cost: 10,
            attack: 'reindeer',
            sell: '5'
        }

    ],
    SANTA: [
        {
            name: 'Santa',
            damage: 50,
            range: 250,
            rate: 500,
            cost: 80,
            attack: 'candycane',
            sell: '40'
        }

    ],
    ELVES: [
        {
            name: 'Elves',
            damage: 25,
            range: 1000,
            rate: 1000,
            cost: 40,
            attack: 'presents',
            sell: '20'
        }

    ],
    FROSTY: [
        {
            name: 'Frosty',
            damage: 10,
            range: 500,
            rate: 1000,
            cost: 20,
            attack: 'snowball',
            sell: '10'
        }
    ]

};
