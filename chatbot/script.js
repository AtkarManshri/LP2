// 🔥 DATA (no fetch, no error)
let data = {
  intents: [
    {
      tag: "greeting",
      patterns: ["hello", "hi", "hey"],
      responses: ["Hello! How can I help you?", "Hi! What do you need?"]
    },
    {
      tag: "appointment",
      patterns: ["book appointment", "see doctor", "schedule visit"],
      responses: ["You can book an appointment from 9 AM to 5 PM."]
    },
    {
      tag: "doctor",
      patterns: ["doctor available", "doctor timing", "is doctor free"],
      responses: ["Doctors are available from 10 AM to 4 PM."]
    },
    {
      tag: "symptoms",
      patterns: ["fever", "cold", "headache","cough"],
      responses: ["You should consult a general physician."]
    },
    {
      tag: "skinsymptoms",
      patterns: ["rash", "redness", "dry skin","irritation"],
      responses: ["You should consult a skin  specialist"]
    },
  ]
};

// Clean text
function clean(text) {
  return text.toLowerCase().replace(/[^\w\s]/g, "");
}

// Similarity logic
function similarity(a, b) {
  let wordsA = a.split(" ");
  let wordsB = b.split(" ");
  let match = wordsA.filter(word => wordsB.includes(word));
  return match.length / Math.max(wordsA.length, wordsB.length);
}

// Get response
function getResponse(msg) {
  msg = clean(msg);

  let bestScore = 0;
  let bestIntent = null;

  data.intents.forEach(intent => {
    intent.patterns.forEach(pattern => {
      let score = similarity(msg, pattern); //rmr

      if (score > bestScore) 
        {
        bestScore = score;
        bestIntent = intent;
        }
    });

  });

  if (bestIntent) {
    let responses = bestIntent.responses;
    return responses[Math.floor(Math.random() * responses.length)];
  }

  return "Sorry, I didn't understand.";
}

// Display message
function displayMessage(text, sender) {
  let chatBox = document.getElementById("chat-box");
  let msg = document.createElement("div");

  msg.classList.add("message", sender);
  msg.innerText = text;

  chatBox.appendChild(msg);
  chatBox.scrollTop = chatBox.scrollHeight;
}

function sendMessage(){
  let input=document.getElementById("user-input");
  let text=input.value.trim();
  if(!text) return;

  displayMessage(text,"user");
  setTimeout(()=>displayMessage(getResponse(text),"bot"),400);
  input.value="";
}

document.getElementById("user-input").onkeypress=e=>{
  if(e.key==="Enter") sendMessage();
};

window.onload=()=>{
  displayMessage("Hello! I am your hospital assistant.","bot");
};