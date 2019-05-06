db.pad.insert([
    {name: "Меркурий", position: {type: "Point", coordinates: [55.750512, 37.539209]}},
    {name: "Таганка", position: {type: "Point", coordinates: [55.738537, 37.655488]}},
    {name: "Сокол-1", position: {type: "Point", coordinates: [55.788572, 37.677854]}},
    {name: "Сокол-2", position: {type: "Point", coordinates: [55.787989, 37.680532]}},
]);

db.pad.createIndex({position: "2dsphere"});