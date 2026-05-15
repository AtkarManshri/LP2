# Knowledge Base (Rules)
rules = [
    {
        "disease": "Flu",
        "symptoms": ["fever", "cough", "fatigue"]
    },
    {
        "disease": "Dengue",
        "symptoms": ["fever", "headache", "joint pain"]
    },
    {
        "disease": "Common Cold",
        "symptoms": ["cough", "cold"]
    },
    {
        "disease": "Migraine",
        "symptoms": ["headache", "fatigue"]
    }
]

def get_user_symptoms():
    print("\nEnter symptoms (yes/no):")
    symptoms_list = ["fever", "cough", "fatigue", "headache", "joint pain", "cold"]
    user_symptoms = []

    for symptom in symptoms_list:
        ans = input(f"Do you have {symptom}? ").lower()
        if ans == "yes":
            user_symptoms.append(symptom)

    return user_symptoms


def forward_chaining(user_symptoms):
    print("\n--- Forward Chaining Result ---")
    found = False

    for rule in rules:
        if all(symptom in user_symptoms for symptom in rule["symptoms"]):
            print(f"Possible Disease: {rule['disease']}")
            found = True

    if not found:
        print("No matching disease found")


def backward_chaining():
    print("\n--- Backward Chaining ---")
    disease = input("Enter disease to check: ")

    for rule in rules:
        if rule["disease"].lower() == disease.lower():
            print(f"Checking symptoms for {disease}...")

            match = True
            for symptom in rule["symptoms"]:
                ans = input(f"Do you have {symptom}? ").lower()
                if ans != "yes":
                    match = False

            if match:
                print(f"Confirmed: You may have {disease}")
            else:
                print(f"{disease} not confirmed")
            return

    print("Disease not in knowledge base")


def main():
    while True:
        print("\n==== Expert System Menu ====")
        print("1. Diagnose (Forward Chaining)")
        print("2. Verify Disease (Backward Chaining)")
        print("3. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            user_symptoms = get_user_symptoms()
            forward_chaining(user_symptoms)

        elif choice == "2":
            backward_chaining()

        elif choice == "3":
            print("Exiting...")
            break

        else:
            print("Invalid choice!")

# Run program
main()