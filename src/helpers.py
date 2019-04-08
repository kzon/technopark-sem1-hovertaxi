def comma_separated_to_float_tuple(data):
    return tuple(map(lambda elem: float(elem), data.split(',')))
