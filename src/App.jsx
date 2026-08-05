import Navbar from "./components/navbar";
import Hero from "./components/Hero.jsx"
import About from "./components/About.jsx";
import Skills from "./Components/Skills.jsx";
import Projects from "./Components/Projects.jsx";
import Journey from "./Components/Journey.jsx";
import Contact from "./Components/Contacts.jsx";
import Footer from "./components/Footer";
function App () {
  return(
    <div className="text-white min-h-screen" >
    <Navbar />
    <Hero /> 
    <About />
    <Skills />
    <Projects />
    <Journey />
    <Contact />
    <Footer />
     <h1  className="text-6x1 font-bold text-center mt-10">Hey, this is Pacifista 2 speaking</h1>
    </div>
   
  );
}
export default App;