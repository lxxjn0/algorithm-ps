import collections

# result = vinko
participant = ["marina", "josipa", "nikola", "vinko", "filipa"]
completion = ["josipa", "filipa", "marina", "nikola"]


def solution(_participant, _completion):
    completion_size = len(_completion)

    sorted_participant = sorted(_participant)  # _participant.sort()도 가능
    sorted_completion = sorted(_completion)  # _completion.sort()도 가능

    for i in range(completion_size):
        if sorted_participant[i] != sorted_completion[i]:
            return sorted_participant[i]
    return sorted_participant[completion_size]


def solution_counter(_participant, _completion):
    answer = collections.Counter(_participant) - collections.Counter(_completion)
    return list(answer.keys())[0]
