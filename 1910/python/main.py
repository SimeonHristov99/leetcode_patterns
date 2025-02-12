def remove_occurrences(s: str, part: str) -> str:
    stack = ''
    for ch in s:
        stack += ch
        stack = stack.removesuffix(part)
    return stack
