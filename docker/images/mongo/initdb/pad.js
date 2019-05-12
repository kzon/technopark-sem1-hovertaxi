db.pad.insert([
    {name: "Меркурий", position: {type: "Point", coordinates: [55.750512, 37.539209]}},
    {name: "Таганка", position: {type: "Point", coordinates: [55.738537, 37.655488]}},
    {name: "Сокол-1", position: {type: "Point", coordinates: [55.788572, 37.677854]}},
    {name: "Сокол-2", position: {type: "Point", coordinates: [55.787989, 37.680532]}},
    {name: "Арбат", position: {type: "Point", coordinates: [55.751977, 37.593087]}},
    {name: "МИД", position: {type: "Point", coordinates: [55.748602, 37.583305]}},
    {name: "МГТУ", position: {type: "Point", coordinates: [55.765739, 37.685647]}},
    {name: "Атриум", position: {type: "Point", coordinates: [55.758105, 37.658550]}},
    {name: "Театральный", position: {type: "Point", coordinates: [55.760340, 37.625748]}},
    {name: "Тверская", position: {type: "Point", coordinates: [55.762245, 37.609256]}},
    {name: "Пушкин", position: {type: "Point", coordinates: [55.763263, 37.604787]}},
    {name: "Планетарий", position: {type: "Point", coordinates: [55.760940, 37.583357]}},
    {name: "Киев", position: {type: "Point", coordinates: [55.745877, 37.569459]}},
    {name: "Добрынинская", position: {type: "Point", coordinates: [55.730164, 37.624789]}},
]);

db.pad.createIndex({position: "2dsphere"});