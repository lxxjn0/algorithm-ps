# result = false
phone_book = ["123", "456", "789"]


def solution(_phone_book):
    _phone_book.sort()

    for i in range(1, len(_phone_book)):
        if _phone_book[i - 1] == _phone_book[i][:len(_phone_book[i - 1])]:
            return False
    return True


def solution_zip(_phone_book):
    _phone_book.sort()

    for p1, p2 in zip(_phone_book, _phone_book[1:]):
        if p2.startswith(p1):
            return False
    return True
