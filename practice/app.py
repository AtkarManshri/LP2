import streamlit as st

experts = {

    "General Physician": {
        "symptoms": [
            "fever",
            "cough",
            "cold"
        ],
        "time": "10 AM to 5 PM"
    },

    "Skin Specialist": {
        "symptoms": [
            "rashes",
            "irritation",
            "itching"
        ],
        "time": "11 AM to 4 PM"
    }
}

general = {

    "hi": "Hello!",

    "doctor available":
    "Doctors available till 5 PM.",

    "appointment":
    "Appointments available."
}

st.title("Hospital Chatbot")

if "messages" not in st.session_state:

    st.session_state.messages = [

        {
            "role":"assistant",

            "content":
            """Ask like:

hi \n
doctor available \n
appointment \n
General Physician \n
I have fever and cough \n
I have rashes \n 
"""
        }
    ]

# show messages
for msg in st.session_state.messages:

    with st.chat_message(msg["role"]):

        st.write(msg["content"])

# input
user_input = st.chat_input("Type here")

if user_input:

    st.session_state.messages.append({

        "role":"user",
        "content":user_input
    })

    msg = user_input.lower()

    reply = "Not understood"

    # general replies
    for key in general:

        if key in msg:

            reply = general[key]

    # doctor timing
    for doctor in experts:

        if doctor.lower() in msg:

            reply = (
                f"{doctor} available "
                f"{experts[doctor]['time']}"
            )

    # symptom checking
    for doctor in experts:

        for symptom in experts[doctor]["symptoms"]:

            if symptom in msg:

                reply = (
                    f"Contact {doctor} "
                    f"{experts[doctor]['time']}"
                )

    st.session_state.messages.append({

        "role":"assistant",
        "content":reply
    })

    st.rerun()