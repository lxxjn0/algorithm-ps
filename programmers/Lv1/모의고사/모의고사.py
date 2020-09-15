from itertools import cycle

# result = [1, 2, 3]
answers = [1, 3, 2, 4, 2]
participant_1 = [1, 2, 3, 4, 5]
participant_2 = [2, 1, 2, 3, 2, 4, 2, 5]
participant_3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]


def solution(_answers):
    collect_answer = [0] * 3
    problem_size = len(_answers)
    for i in range(problem_size):
        if _answers[i] == participant_1[i % len(participant_1)]:
            collect_answer[0] += 1
        if _answers[i] == participant_2[i % len(participant_2)]:
            collect_answer[1] += 1
        if _answers[i] == participant_3[i % len(participant_3)]:
            collect_answer[2] += 1
    answer = [i + 1 for i in range(len(collect_answer)) if collect_answer[i] == max(collect_answer)]
    return answer


def solution_enumerate(_answers):
    participants = [participant_1, participant_2, participant_3]
    correct_answers = [0] * len(participants)

    for answer_index, answer in enumerate(_answers):
        for participant_index, participant in enumerate(participants):
            if answer == participant[answer_index % len(participant)]:
                correct_answers[participant_index] += 1
    return [index + 1 for index, correct_size in enumerate(correct_answers) if correct_size == max(correct_answers)]


def solution_cycle(_answers):
    participants = [
        cycle(participant_1),
        cycle(participant_2),
        cycle(participant_3),
    ]
    correct_answers = [0] * len(participants)

    for answer in _answers:
        for participant_index, participant in enumerate(participants):
            if answer == next(participant):
                correct_answers[participant_index] += 1
    return [index + 1 for index, correct_size in enumerate(correct_answers) if correct_size == max(correct_answers)]
